pub mod input;

use regex::Regex;

pub fn run() {
    println!("{:?}", multiply(input::EXAMPLE));
    println!("{:?}", multiply(input::INPUT));
    println!("{:?}", multiply_on_off(input::EXAMPLE));
}

fn multiply(input: &str) -> i64 {
    let re: Regex = Regex::new(r"mul\((\d+),(\d+)\)").unwrap();

    let mut product_sum: i64 = 0;
    for c in re.captures_iter(input) {
        let (_, [first, second]) = c.extract();
        let first: i64 = match first.parse::<i64>() {
            Ok(n) => n,
            Err(e) => {
                println!("Error: {}", e);
                return 0;
            }
        };
        let second: i64 = match second.parse::<i64>() {
            Ok(n) => n,
            Err(e) => {
                println!("Error: {}", e);
                return 0;
            }
        };

        product_sum += first * second;
    }

    product_sum
}

fn multiply_on_off(input: &str) -> i64 {
    let re: Regex = Regex::new(r"((do\(\)|don't\(\)).*?)?mul\((\d+),(\d+)\)").unwrap();
    let mut enabled: bool = true;

    let mut product_sum: i64 = 0;
    for c in re.captures_iter(input) {
        println!("{:?}", c);
        if let Some(toggle_match) = c.get(2) {
            enabled = match toggle_match.as_str() {
                "do()" => true,
                "don't()" => false,
                _ => enabled,
            };
        }

        if enabled {
            let first: i64 = match c.get(3).expect("").as_str().parse::<i64>() {
                Ok(n) => n,
                Err(e) => {
                    println!("Error: {}", e);
                    return 0;
                }
            };
            let second: i64 = match c.get(4).expect("").as_str().parse::<i64>() {
                Ok(n) => n,
                Err(e) => {
                    println!("Error: {}", e);
                    return 0;
                }
            };

            product_sum += first * second;
        }
    }

    product_sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn problem1_example() {
        assert_eq!(multiply(input::EXAMPLE), 161);
    }

    #[test]
    fn problem1_input() {
        assert_eq!(multiply(input::INPUT), 161085926);
    }

    #[test]
    fn problem2_example() {
        assert_eq!(multiply_on_off(input::EXAMPLE), 48);
    }

    #[test]
    fn problem2_input() {
        assert_eq!(multiply_on_off(input::INPUT), 0);
    }
}

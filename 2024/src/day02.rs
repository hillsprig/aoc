pub mod input;

pub fn run() {
    println!("{:?}", safe(input::EXAMPLE));
    println!("{:?}", safe(input::INPUT));
    println!("{:?}", safe_dampener(input::EXAMPLE));
    println!("{:?}", safe_dampener(input::INPUT));
}

fn safe(input: &[&[i32]]) -> u32 {
    let mut safe_reports: u32 = 0;

    'outer: for report in input {
        if !safe_check(report.to_vec(), 1) {
            continue 'outer;
        }

        safe_reports += 1;
    }

    safe_reports
}

fn safe_dampener(input: &[&[i32]]) -> u32 {
    let mut safe_reports: u32 = 0;

    'outer: for &report in input {
        println!("TRYING: {:?}", report);
        if !safe_check(report.to_vec(), 0) {
            println!("FAIL: {:?}", report);
            continue 'outer;
        }

        println!("PASS: {:?}", report);
        safe_reports += 1;
    }

    safe_reports
}

fn safe_check(input: Vec<i32>, errors: u32) -> bool {
    if input.len() < 2 {
        return false;
    }

    let increasing = input[0] < input[1];

    let mut idx: usize = 0;
    let mut iter = input.iter().peekable();
    while let Some(&value) = iter.next() {
        if let Some(&&value_next) = iter.peek() {
            let increasing_next = value < value_next;
            let abs_diff = value.abs_diff(value_next);

            if increasing != increasing_next || !(1..=3).contains(&abs_diff) {
                if errors == 0 {
                    let mut zero: Vec<i32> = input.to_owned();
                    let mut first: Vec<i32> = input.to_owned();
                    let mut second: Vec<i32> = input.to_owned();
                    if idx > 0 {
                        zero.remove(idx - 1);
                    } else {
                        zero = vec![];
                    }
                    first.remove(idx);
                    second.remove(idx + 1);
                    println!("-> TRYING: {:?}", first);
                    println!("-> TRYING: {:?}", second);
                    return safe_check(zero, 1) || safe_check(first, 1) || safe_check(second, 1);
                } else {
                    return false;
                }
            }
        }
        idx += 1;
    }

    true
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn problem1_example() {
        assert_eq!(safe(input::EXAMPLE), 2);
    }

    #[test]
    fn problem1_input() {
        assert_eq!(safe(input::INPUT), 572);
    }

    #[test]
    fn problem2_example() {
        assert_eq!(safe_dampener(input::EXAMPLE), 5);
    }

    #[test]
    fn problem2_input() {
        assert_eq!(safe_dampener(input::INPUT), 612);
    }
}

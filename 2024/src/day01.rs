pub mod input;

pub fn run() {
    println!("{:?}", distance_sum(input::EXAMPLE));
    println!("{:?}", distance_sum(input::INPUT));
    println!("{:?}", similarity_score(input::EXAMPLE));
    println!("{:?}", similarity_score(input::INPUT));
}

fn distance_sum(input: &[(i32, i32)]) -> u32 {
    let (mut left, mut right) = (Vec::new(), Vec::new());
    for &i in input {
        left.push(i.0);
        right.push(i.1);
    }
    left.sort_unstable();
    right.sort_unstable();

    let mut sum = 0;
    for p in left.into_iter().zip(right.into_iter()) {
        sum += p.0.abs_diff(p.1);
    }

    sum
}

fn similarity_score(input: &[(i32, i32)]) -> u32 {
    let (mut left, mut right) = (Vec::new(), Vec::new());
    for &i in input {
        left.push(i.0);
        right.push(i.1);
    }
    left.sort_unstable();
    right.sort_unstable();

    let mut score: u32 = 0;
    for l in left.into_iter() {
        let mut occurences: u32 = 0;
        for r in right.iter() {
            if l == *r {
                occurences += 1;
            }
        }
        score += l.unsigned_abs() * occurences;
    }

    score
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn problem1_example() {
        assert_eq!(distance_sum(input::EXAMPLE), 11);
    }

    #[test]
    fn problem1_input() {
        assert_eq!(distance_sum(input::INPUT), 2176849);
    }

    #[test]
    fn problem2_example() {
        assert_eq!(similarity_score(input::EXAMPLE), 31);
    }

    #[test]
    fn problem2_input() {
        assert_eq!(similarity_score(input::INPUT), 23384288);
    }
}

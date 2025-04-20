pub mod input;

pub fn run() {
    println!("{:?}", safe(input::EXAMPLE));
    println!("{:?}", safe(input::INPUT));
}

fn safe(input: &[&[i32]]) -> u32 {
    let mut safe_reports: u32 = 0;
    'outer: for report in input.iter() {
        let increasing = report[0] - report[1] > 0;

        for i in report.windows(2) {
            if increasing && i[0] - i[1] > 0 {
            } else {
                continue 'outer;
            }
            if i[0].abs_diff(i[1]) >= 1 && i[0].abs_diff(i[1]) <= 3 {
            } else {
                continue 'outer;
            }
        }
        safe_reports += 1;
    }

    safe_reports
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn problem1_example() {
        assert_eq!(safe(input::EXAMPLE), 0);
    }
}

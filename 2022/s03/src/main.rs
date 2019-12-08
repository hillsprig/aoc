use std::collections::BTreeSet;
use std::fs;

fn main() {
    let contents = fs::read_to_string("input.txt").unwrap();

    let matches: Vec<&str> = contents.split("\n").collect();
    let mut sum: i32 = 0;
    for m in &matches {
        if m.is_empty() {
            continue;
        }

        let (a, b) = cleave_string(&m);

        println!("{a} {b}");
        let set1 = BTreeSet::from_iter(a.chars());
        let set2 = BTreeSet::from_iter(b.chars());

        let intersection: Vec<_> = set1.intersection(&set2).cloned().collect();

        println!(
            "{} as {} -> {}",
            intersection[0],
            intersection[0] as i32,
            get_priority(intersection[0])
        );

        sum += get_priority(intersection[0]);
    }

    println!("{sum}");

    sum = 0;
    let mut sets: Vec<BTreeSet<char>> = Vec::new();
    for (_i, m) in matches.iter().enumerate() {
        if m.is_empty() {
            continue;
        }

        sets.push(BTreeSet::from_iter(m.chars()));

        if sets.len() == 3 {
            let intersection1: BTreeSet<_> = sets[0].intersection(&sets[1]).cloned().collect();
            let final_intersection: Vec<_> =
                intersection1.intersection(&sets[2]).cloned().collect();

            println!(
                "{} -> {}",
                final_intersection[0],
                get_priority(final_intersection[0])
            );
            sum += get_priority(final_intersection[0]);

            sets.clear();
        }
    }

    println!("{sum}");
}

fn cleave_string(s: &str) -> (&str, &str) {
    (
        &s[0..s.chars().count() / 2],
        &s[s.chars().count() / 2..s.chars().count()],
    )
}

fn get_priority(c: char) -> i32 {
    if c as i32 >= 65 && c as i32 <= 90 {
        return c as i32 - 38;
    } else if c as i32 >= 97 && c as i32 <= 122 {
        return c as i32 - 96;
    }

    return 0;
}

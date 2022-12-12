use std::collections::VecDeque;
use std::fs;

fn main() {
    let contents = fs::read_to_string("input.txt").unwrap();

    let matches: Vec<&str> = contents.split("\n").collect();

    for m in matches {
        let mut keyset: VecDeque<char> = VecDeque::new();
        for (i, c) in m.chars().enumerate() {
            if keyset.contains(&c) {
                let index = keyset.iter().position(|&r| r == c).unwrap();
                for _ in 0..index + 1 {
                    keyset.pop_front();
                }
            }
            keyset.push_back(c);

            if keyset.len() == 14 {
                println!("{:?} {}", keyset, i + 1);
                break;
            }
        }
    }
}

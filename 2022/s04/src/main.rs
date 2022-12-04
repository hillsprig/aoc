use std::collections::BTreeSet;
use std::fs;

fn main() {
    let contents = fs::read_to_string("input.txt").unwrap();

    let matches: Vec<&str> = contents.split("\n").collect();

    let mut pairs = 0;
    let mut any_overlap = 0;
    for m in &matches {
        if m.is_empty() {
            continue;
        }

        let (a, b) = get_ranges(&m);

        let intersection: Vec<_> = a.intersection(&b).cloned().collect();

        println!("{} - {:?} : {:?} -> {:?}", m, a, b, intersection);

        if intersection.len() == a.len() || intersection.len() == b.len() {
            pairs += 1;
        }

        if intersection.len() > 0 {
            any_overlap += 1;
        }
    }

    println!("{pairs}");
    println!("{any_overlap}");
}

fn get_ranges(r: &str) -> (BTreeSet<i64>, BTreeSet<i64>) {
    let range: Vec<&str> = r.split(",").collect();

    return (get_range(range[0]), get_range(range[1]));
}

fn get_range(r: &str) -> BTreeSet<i64> {
    let edges: Vec<&str> = r.split("-").collect();

    let begin: i64 = edges[0].parse().unwrap();
    let end: i64 = edges[1].parse().unwrap();

    return BTreeSet::from_iter(begin..end + 1);
}

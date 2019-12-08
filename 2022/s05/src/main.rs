use regex::Regex;
use std::collections::VecDeque;
use std::fs;

fn main() {
    let contents = fs::read_to_string("input.txt").unwrap();

    let matches: Vec<&str> = contents.split("\n").collect();

    let mut first: Vec<&str> = Vec::new();
    let mut second: Vec<&str> = Vec::new();

    let mut second_part: bool = false;
    for m in matches {
        if m.is_empty() {
            second_part = true;
            continue;
        }

        if second_part {
            second.push(m);
        } else {
            first.push(m);
        }
    }
    first.pop();

    let mut stacks: Vec<VecDeque<&str>> = Vec::new();

    for row in first {
        let mut stack_index = 0;
        let mut row_index = 1;
        while row_index < row.len() {
            let stack = stacks.get(stack_index);
            if stack == None {
                stacks.push(VecDeque::new());
            }

            let c = &row[row_index..row_index + 1];
            if c != " " {
                stacks[stack_index].push_back(c)
            }
            row_index += 4;
            stack_index += 1;
        }
    }

    println!("{:?}", stacks);

    for c in second {
        println!("{:?}", c);
        println!("{:?}", interpret(c));
        let (m, f, t) = interpret(c);

        let mut tmp_stack: Vec<&str> = Vec::new();
        for n in 0..m {
            println!("{}", n);
            let removed_element = stacks[f - 1].pop_front().unwrap();
            tmp_stack.push(removed_element);
        }

        tmp_stack.reverse();

        for c in tmp_stack {
            stacks[t - 1].push_front(c);
        }
    }

    println!("{:?}", stacks);

    // get answer
    for stack in stacks {
        print!("{}", stack[0]);
    }
    println!("")
}

fn interpret(command: &str) -> (usize, usize, usize) {
    let re = Regex::new(r"^move (\d*) from (\d*) to (\d*)$").unwrap();
    let captures = re.captures_iter(command).next().unwrap();

    (
        captures[1].parse::<usize>().unwrap(),
        captures[2].parse::<usize>().unwrap(),
        captures[3].parse::<usize>().unwrap(),
    )
}

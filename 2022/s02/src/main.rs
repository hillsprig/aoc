use std::fs;

#[derive(PartialEq, Copy, Clone)]
enum Hand {
    Rock = 1,
    Paper = 2,
    Scissors = 3,
    Death,
}

enum OutcomeScore {
    Loss = 0,
    Tie = 3,
    Victory = 6,
}

// Rock
const A: &str = "A";
const X: &str = "X";

// Paper
const B: &str = "B";
const Y: &str = "Y";

// Scissors
const C: &str = "C";
const Z: &str = "Z";

fn main() {
    let contents = fs::read_to_string("input.txt").unwrap();

    let mut total_score: i64 = 0;
    let matches: Vec<&str> = contents.split("\n").collect();
    for m in matches {
        if m.is_empty() {
            continue;
        }
        let players: Vec<&str> = m.split(" ").collect();

        let calc_hand = get_response(get_hand(players[0]), players[1]);

        let outcome = check(calc_hand, get_hand(players[0]));

        total_score += score(calc_hand, outcome)
    }

    println!("{total_score}");
}

fn get_response(opponent: Hand, value: &str) -> Hand {
    // tie
    if value == "Y" {
        return opponent;
    }

    // lose
    if value == "X" {
        if opponent == Hand::Rock {
            return Hand::Scissors;
        } else if opponent == Hand::Paper {
            return Hand::Rock;
        } else if opponent == Hand::Scissors {
            return Hand::Paper;
        }
    }

    if value == "Z" {
        if opponent == Hand::Rock {
            return Hand::Paper;
        } else if opponent == Hand::Paper {
            return Hand::Scissors;
        } else if opponent == Hand::Scissors {
            return Hand::Rock;
        }
    }

    return Hand::Death;
}

fn get_hand(value: &str) -> Hand {
    if value == A as &str || value == X as &str {
        return Hand::Rock;
    }

    if value == B as &str || value == Y as &str {
        return Hand::Paper;
    }

    if value == C as &str || value == Z as &str {
        return Hand::Scissors;
    }

    return Hand::Death;
}

fn check(player: Hand, opponent: Hand) -> OutcomeScore {
    if player == opponent {
        return OutcomeScore::Tie;
    }

    if player == Hand::Rock && opponent == Hand::Scissors {
        return OutcomeScore::Victory;
    }

    if player == Hand::Paper && opponent == Hand::Rock {
        return OutcomeScore::Victory;
    }

    if player == Hand::Scissors && opponent == Hand::Paper {
        return OutcomeScore::Victory;
    }

    return OutcomeScore::Loss;
}

fn score(hand: Hand, outcome: OutcomeScore) -> i64 {
    return hand as i64 + outcome as i64;
}

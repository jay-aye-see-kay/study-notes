use std::collections::HashMap;

fn main() {
    let nums = vec![1, 2, 3, 10, 10];
    println!("nums: {:?}", nums);
    println!("num_stats: {:?}", get_num_stats(&nums));

    let s = "first".to_string();
    println!("string before: {:?}", s);
    println!("string after: {:?}", to_pig_latin(&s));
    println!("\n");
    let s = "apple".to_string();
    println!("string before: {:?}", s);
    println!("string after: {:?}", to_pig_latin(&s));
}

/// Given a list of integers, use a vector and return the mean (the average value), median (when
/// sorted, the value in the middle position), and mode (the value that occurs most often; a hash
/// map will be helpful here) of the list.
fn get_num_stats(v: &Vec<i32>) -> NumStats {
    let mut v = v.to_vec();
    v.sort();

    let mut sum = 0;
    let length = v.len();
    let mut counts: HashMap<i32, i32> = HashMap::new();
    let mut mode = 0;
    let mut mode_count = 0;

    for n in v.iter() {
        sum += n;

        let count = counts.entry(*n).or_insert(0);
        *count += 1;

        if *count > mode_count {
            mode = *n;
            mode_count = *count;
        }
    }
    println!("counts: {:?}", counts);

    let median = if length % 2 != 0 {
        // odd
        let median = v[(length - 1) / 2];
        median as f64
    } else {
        // even
        let mid = ((length - 1) as f64) / 2.0;
        let m0 = mid.floor() as usize;
        let m1 = mid.ceil() as usize;
        let v0 = v[m0] as f64;
        let v1 = v[m1] as f64;

        (v0 + v1) / 2.0
    };

    return NumStats {
        mean: (sum as f64) / (length as f64),
        median,
        mode,
    };
}

#[derive(Debug)]
struct NumStats {
    mean: f64,
    median: f64,
    mode: i32,
}

/// Convert strings to pig latin. The first consonant of each word is moved to the end of the word
/// and “ay” is added, so “first” becomes “irst-fay.” Words that start with a vowel have “hay”
/// added to the end instead (“apple” becomes “apple-hay”). Keep in mind the details about UTF-8
/// encoding!
fn to_pig_latin(s: &str) -> String {
    if s.starts_with('a')
        || s.starts_with('e')
        || s.starts_with('i')
        || s.starts_with('o')
        || s.starts_with('u')
    {
        return format!("{}-hay", s);
    }

    let mut new_s = s.to_string();
    let first_char = new_s.remove(0);
    format!("{}-{}ay", new_s, first_char)
}

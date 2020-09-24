pub struct Counter {
    count: u32,
}

impl Counter {
    pub fn new() -> Counter {
        Counter { count: 0 }
    }
}

impl Iterator for Counter {
    type Item = u32;

    fn next(&mut self) -> Option<Self::Item> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn calling_next_directly() {
        let mut counter = Counter::new();

        assert_eq!(counter.next(), Some(1));
        assert_eq!(counter.next(), Some(2));
        assert_eq!(counter.next(), Some(3));
        assert_eq!(counter.next(), Some(4));
        assert_eq!(counter.next(), Some(5));
        assert_eq!(counter.next(), None);
    }

    #[test]
    fn turn_it_into_a_vec() {
        let counter = Counter::new();
        let inc = 1;

        let v: Vec<u32> = counter.into_iter().map(|x| x + inc).collect();

        assert_eq!(v, vec![2, 3, 4, 5, 6]);
    }

    #[test]
    fn loop_over_it() {
        let counter = Counter::new();

        let mut v: Vec<u32> = vec![];
        for x in counter.into_iter() {
            v.push(x);
        }

        assert_eq!(v, vec![1, 2, 3, 4, 5]);
    }
}

pub fn main() {}

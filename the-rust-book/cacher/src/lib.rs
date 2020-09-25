use std::collections::HashMap;

pub struct Cacher<T>
where
    T: Fn(u32) -> u32,
{
    calculation: T,
    values: HashMap<u32, u32>,
}

impl<T> Cacher<T>
where
    T: Fn(u32) -> u32,
{
    pub fn new(calculation: T) -> Cacher<T> {
        Cacher {
            calculation,
            values: HashMap::new(),
        }
    }

    pub fn value(&mut self, arg: u32) -> u32 {
        match self.values.get(&arg) {
            Some(v) => *v,
            None => {
                let v = (self.calculation)(arg);
                self.values.insert(arg, v);
                v
            }
        }
    }
}

#[cfg(test)]
mod cacher_tests {
    use super::*;
    use std::cell::RefCell;

    #[test]
    fn it_caches_one_value() {
        let exec_count = RefCell::new(0);

        let mut cached = Cacher::new(|x| {
            *exec_count.borrow_mut() += 1;
            x
        });

        let res_1 = cached.value(1);
        let res_2 = cached.value(1);

        // should return the same value, but only call the fn once
        assert_eq!(res_1, res_2);
        assert_eq!(*exec_count.borrow(), 1);
    }

    #[test]
    fn it_caches_multiple_values() {
        let exec_count = RefCell::new(0);

        let mut cached = Cacher::new(|x| {
            *exec_count.borrow_mut() += 1;
            x
        });

        let res_1 = cached.value(1);
        let res_2 = cached.value(9);
        let _ = cached.value(1);
        let _ = cached.value(9);
        let res_3 = cached.value(1);
        let res_4 = cached.value(9);

        // should return two independance results in whatever order
        assert_eq!(res_1, res_3);
        assert_eq!(res_2, res_4);

        // should be called once per value cached
        assert_eq!(*exec_count.borrow(), 2);
    }
}

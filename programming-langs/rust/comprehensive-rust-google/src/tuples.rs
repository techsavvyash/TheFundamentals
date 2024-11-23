fn main() {
  let t: (i8, bool) = (2, true);
  println!("t1: {}", t.0);
  println!("t2: {}", t.1);

  // let's talk about destructuring here
  let (num, flag) = t;
  println!("num : {}", num);
  println!("flag: {}", flag);
}
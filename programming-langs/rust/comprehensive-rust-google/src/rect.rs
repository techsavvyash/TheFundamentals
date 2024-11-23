#[derive(Debug)]
struct Rectangle {
  width: u32,
  height: u32,
}

fn main() {
  let rect = Rectangle { width: 4, height: 6};
  let rect_area = area(&rect);
  println!("area of rect with width: {} and height: {} is: {}", rect.width, rect.height, rect_area);
  dbg!(&rect);
}

fn area(rect: &Rectangle) -> u32 {
  rect.width * rect.height
}
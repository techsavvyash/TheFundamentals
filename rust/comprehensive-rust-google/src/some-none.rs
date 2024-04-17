fn maybe_return_some() -> Option<i32> {
    Some(42)
}

fn maybe_return_none() -> Option<i32> {
    None
}

fn main() {
    // Check if the function returns Some
    if let Some(value) = maybe_return_some() {
        println!("Returned Some: {}", value);
    } else {
        println!("Returned None");
    }

    // Check if the function returns None
    if let Some(value) = maybe_return_none() {
        println!("Returned Some: {}", value);
    } else {
        println!("Returned None");
    }
}

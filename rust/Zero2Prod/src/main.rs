use std::net::TcpListener;
use zero_2_prod::run;

#[tokio::main]
async fn main() -> Result<(), std::io::Error> {
    let lst = TcpListener::bind("127.0.0.1:0").expect("Failed to bind random port");
    run(lst)?.await
}

// use crate::startup::run;
use sqlx::PgPool;
use std::net::TcpListener;
use zero_2_prod::{configuration::get_config, startup::run};
#[tokio::main]
async fn main() -> Result<(), std::io::Error> {
    // read config
    let configuration = get_config().expect("Failed to read env");
    let conn_poll = PgPool::connect(&configuration.database.connection_string())
        .await
        .expect("Failed to connect to the db.");
    let address = format!("127.0.0.1:{}", configuration.application_port);
    let lst = TcpListener::bind(address)?;
    run(lst, conn_poll)?.await
}

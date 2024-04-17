use crate::routes::{health_check, subscription};
use actix_web::dev::Server;
use actix_web::{web, App, HttpServer};
use sqlx::PgPool;
use std::net::TcpListener;

pub fn run(listener: TcpListener, db_poll: PgPool) -> Result<Server, std::io::Error> {
    let db_poll = web::Data::new(db_poll);
    let server = HttpServer::new(move || {
        App::new()
            .route("/health_check", web::get().to(health_check))
            .route("/subscriptions", web::post().to(subscription))
            .app_data(db_poll.clone())
    })
    .listen(listener)?
    .run();

    // no await here
    Ok(server)
}

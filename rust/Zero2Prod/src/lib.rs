use actix_web::dev::Server;
use actix_web::{web, App, HttpResponse, HttpServer};
use std::net::TcpListener;

#[derive(serde::Deserialize)]
pub struct SubscriptionFormData {
    name: String,
    email: String,
}

async fn health_check() -> HttpResponse {
    // Trait Responsder is nothing but conversion into HttpResponse
    HttpResponse::Ok().finish()
}

async fn subscription(_subscriber_details: web::Form<SubscriptionFormData>) -> HttpResponse {
    // Steps for this would be?
    // Figure out how to extract the form data from the request
    // Validate the form data
    // Return a 400 Bad Request response if the form data is invalid
    // all the above things are being done by using the arguments and struct by actix-web
    HttpResponse::Ok().finish()
}

pub fn run(listener: TcpListener) -> Result<Server, std::io::Error> {
    let server = HttpServer::new(|| {
        App::new()
            .route("/health_check", web::get().to(health_check))
            .route("/subscriptions", web::post().to(subscription))
    })
    .listen(listener)?
    .run();

    // no await here
    Ok(server)
}

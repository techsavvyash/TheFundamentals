use actix_web::HttpResponse;

pub async fn health_check() -> HttpResponse {
    // Trait Responsder is nothing but conversion into HttpResponse
    HttpResponse::Ok().finish()
}

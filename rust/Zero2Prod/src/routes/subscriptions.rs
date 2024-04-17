use actix_web::{web, HttpResponse};

#[derive(serde::Deserialize)]
pub struct SubscriptionFormData {
    name: String,
    email: String,
}

pub async fn subscription(_subscriber_details: web::Form<SubscriptionFormData>) -> HttpResponse {
    // Steps for this would be?
    // Figure out how to extract the form data from the request
    // Validate the form data
    // Return a 400 Bad Request response if the form data is invalid
    // all the above things are being done by using the arguments and struct by actix-web
    HttpResponse::Ok().finish()
}

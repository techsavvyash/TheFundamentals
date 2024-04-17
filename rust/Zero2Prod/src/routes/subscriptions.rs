use actix_web::{web, HttpResponse};
use chrono::Utc;
use sqlx::PgPool;
use uuid::Uuid;

#[derive(serde::Deserialize)]
pub struct SubscriptionFormData {
    name: String,
    email: String,
}

pub async fn subscription(
    _subscriber_details: web::Form<SubscriptionFormData>,
    pool: web::Data<PgPool>,
) -> HttpResponse {
    // Steps for this would be?
    // Figure out how to extract the form data from the request
    // Validate the form data
    // Return a 400 Bad Request response if the form data is invalid
    // all the above things are being done by using the arguments and struct by actix-web
    match sqlx::query!(
        r#"
      INSERT INTO subscription (id, email, name, subscribed_at)
      VALUES ($1, $2, $3, $4)
      "#,
        Uuid::new_v4(),
        _subscriber_details.email,
        _subscriber_details.name,
        Utc::now()
    )
    .execute(pool.get_ref())
    .await
    {
        Ok(_) => HttpResponse::Ok().finish(),
        Err(e) => {
            println!("Failed to execute query: {:?}", e);
            HttpResponse::InternalServerError().finish()
        }
    }
}

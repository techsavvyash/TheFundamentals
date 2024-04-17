use std::net::TcpListener;
use zero_2_prod::startup::run;

// This function launches the app in the background somehow
fn spawn_app() -> String {
    let lst = TcpListener::bind("127.0.0.1:0").expect("Failed to bind random port");
    let port = lst.local_addr().unwrap().port();
    let server = run(lst).expect("Failed to bind address");
    // Launch the server as a background task
    // tokio::spawn returns a handle to the spawned future,
    // but we have no use for it here, hence the non-binding let
    let _ = tokio::spawn(server);

    format!("http://127.0.0.1:{}", port)
}
#[tokio::test]
async fn health_check_works() {
    // Arrange
    let port = spawn_app();
    let client = reqwest::Client::new();

    let response = client
        .get(&format!("{}/health_check", &port))
        .send()
        .await
        .expect("Failed to execute request.");

    assert!(response.status().is_success());
    assert_eq!(Some(0), response.content_length());
}

#[tokio::test]
async fn subscribe_status_ok() {
    let port = spawn_app();
    let client = reqwest::Client::new();
    let body = "name=yash%20mittal&email=yash%40example.com";
    let response = client
        .post(&format!("{}/subscriptions", &port))
        .header("Content-Type", "application/x-www-form-urlencoded")
        .body(body)
        .send()
        .await
        .expect("Failed to execute request.");

    assert!(response.status().is_success());
    assert_eq!(200, response.status().as_u16());
}

#[tokio::test]
async fn subscribe_status_bad() {
    let port = spawn_app();
    let client = reqwest::Client::new();
    let test_cases = vec![
        ("name=le%20guin", "missing the email"),
        ("email=ursula_le_guin%40gmail.com", "missing the name"),
        ("", "missing both name and email"),
    ];
    for (body, err_msg) in test_cases {
        let response = client
            .post(&format!("{}/subscriptions", &port))
            .header("Content-Type", "application/x-www-form-urlencoded")
            .body(body)
            .send()
            .await
            .expect("Failed to execute request.");

        // assert!(response.status().is_client_error());
        assert_eq!(
            400,
            response.status().as_u16(),
            // in case the test fails here (i.e. the API returns a non 400 status code) we can prints the following debug info
            "The API did not return a 400 Bad Request when the payload was {}.",
            err_msg
        );
    }
}

use std::net::TcpListener;

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

// This function launches the app in the background somehow
fn spawn_app() -> String {
    let lst = TcpListener::bind("127.0.0.1:0").expect("Failed to bind random port");
    let port = lst.local_addr().unwrap().port();
    let server = zero_2_prod::run(lst).expect("Failed to bind address");
    // Launch the server as a background task
    // tokio::spawn returns a handle to the spawned future,
    // but we have no use for it here, hence the non-binding let
    let _ = tokio::spawn(server);

    format!("http://127.0.0.1:{}", port)
}

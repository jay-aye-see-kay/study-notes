use serde::Deserialize;

#[derive(Debug, Deserialize)]
struct RResponse {
    kind: String,
    data: RData,
}

#[derive(Debug, Deserialize)]
struct RData {
    dist: i32,
    children: Vec<RPost>,
}

#[derive(Debug, Deserialize)]
struct RPost {
    kind: String,
    data: RPostData,
}

#[derive(Debug, Deserialize)]
struct RPostData {
    subreddit: String,
    title: String,
    permalink: String,
    author: String,
    domain: String,
    url: String,
    created: f64,
    created_utc: f64,
    ups: i32,
    downs: i32,
    score: i32,
    num_comments: i32,
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let body: RResponse = reqwest::blocking::get("https://reddit.com/r/all.json")?.json()?;

    let first_post = body.data.children.first().unwrap();
    println!("first_post: {:?}", first_post);
    Ok(())
}

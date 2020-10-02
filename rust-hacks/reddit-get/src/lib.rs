use serde::Deserialize;
use reqwest::blocking;

#[derive(Debug, Deserialize)]
pub struct RResponse {
    pub kind: String,
    pub data: RData,
}

#[derive(Debug, Deserialize)]
pub struct RData {
    pub dist: i32,
    pub children: Vec<RPost>,
}

#[derive(Debug, Deserialize)]
pub struct RPost {
    pub kind: String,
    pub data: RPostData,
}

#[derive(Debug, Deserialize)]
pub struct RPostData {
    pub subreddit: String,
    pub title: String,
    pub permalink: String,
    pub author: String,
    pub domain: String,
    pub url: String,
    pub created: f64,
    pub created_utc: f64,
    pub ups: i32,
    pub downs: i32,
    pub score: i32,
    pub num_comments: i32,
}


pub fn get_sub(sub: Option<&str>) -> Result<RResponse, Box<dyn std::error::Error>> {
    let sub = match sub {
        Some(sub) => sub,
        None => "all",
    };
    let url = format!("https://reddit.com/r/{}.json", sub);

    let body: RResponse = blocking::get(&url)?.json()?;
    Ok(body)
}

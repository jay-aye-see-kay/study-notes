use reqwest::blocking;
use serde::Deserialize;

#[derive(Debug, Deserialize)]
pub struct RResponse {
    kind: String,
    pub data: RData,
}

#[derive(Debug, Deserialize)]
pub struct RData {
    dist: i32,
    pub children: Vec<RPost>,
}

#[derive(Debug, Deserialize)]
pub struct RPost {
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

impl std::fmt::Display for RPost {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{title} (from: /r/{sub} /u/{user})\n{url}",
            title = &self.data.title,
            sub = &self.data.subreddit,
            user = &self.data.author,
            url = &self.data.url
        )
    }
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

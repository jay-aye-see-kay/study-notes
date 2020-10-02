use reqwest::blocking;
use serde::Deserialize;
use termion::{color, style};

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
            "{title} (from: /r/{sub} /u/{author})\n{url}",
            title = self.data.title,
            sub = self.data.subreddit,
            author = self.data.author,
            url = self.data.url
        )
    }
}

impl RPost {
    pub fn term_print(&self, index: usize) {
        print!(
            "{blue}/r/{sub}{reset}\n",
            blue = color::Fg(color::Blue),
            sub = self.data.subreddit,
            reset = style::Reset
        );
        print!("{}:", index);
        print!(
            " {red}{bold}{title}{reset}",
            red=color::Fg(color::Red),
            bold=style::Bold,
            title=self.data.title,
            reset=style::Reset
        );
        print!(
            " {green}/u/{author}{reset}\n",
            green = color::Fg(color::Green),
            author = self.data.author,
            reset = style::Reset
        );
        print!("{}\n", self.data.url);
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

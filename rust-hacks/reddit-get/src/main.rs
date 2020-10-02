use reddit_get::get_sub;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let body = get_sub(None)?;

    for (i, post) in body.data.children.iter().enumerate() {
        post.term_print(i + 1);
        println!("");
    }

    Ok(())
}

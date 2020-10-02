use reddit_get::get_sub;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let body = get_sub(None)?;

    let first_post = body.data.children.first().unwrap();
    println!("first_post: {:?}", first_post);
    Ok(())
}

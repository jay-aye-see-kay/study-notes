use reddit_get::get_sub;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let body = get_sub(None)?;

    for (i, post) in body.data.children.iter().enumerate() {
        println!("{}: {}\n", i + 1, post);
    }

    Ok(())
}

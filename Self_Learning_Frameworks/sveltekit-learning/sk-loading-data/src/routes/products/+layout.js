export const load = async (LoadEvent) => {
    const {fetch, parent} = LoadEvent;
    const parentData = await parent();
    const {username} = parentData;
    const title = "Featured Products";
    const response = await fetch('http://localhost:4000/featured-products');
    const featuredProducts = await response.json();
    return {
        username,
        title,
        featuredProducts
    };
}


// import Product from './product.svelte';

export const load = async (serverloadEvent) => {
    console.log('Load function called in page.server.js')
    const {fetch} = serverloadEvent;
    const title = `List of available products`;
    const response = await fetch("http://localhost:4000/products")
    const products = await response.json();
    return {
        title,
        products
        // Component : Component --> error in a server Load Function
    };
}
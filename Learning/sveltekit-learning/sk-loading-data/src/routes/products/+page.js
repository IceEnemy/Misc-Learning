import Product from './product.svelte';

export const load = async (loadEvent) => {
    console.log('Load function called in page.js')
    const {data, parent} = loadEvent;
    const parentData = await parent();
    const {username} = parentData;
    const notification = "End of season sale!"
    // const title = 'List of available products';
    // const response = await fetch("http://localhost:4000/products")
    // const products = await response.json();
    return {
        // title,
        // products,
        ...data,
        username,
        notification,
        Component: Product
    };
}

export const prerender = true;
export const ssr = true;
export const csr = true;
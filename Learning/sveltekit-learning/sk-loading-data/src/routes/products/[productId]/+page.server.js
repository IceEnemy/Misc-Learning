import { error } from '@sveltejs/kit'
import exp from 'constants';
// import {redirect} from '@sveltejs/kit';

export const load = async (serverLoadEvent) => {
    const {fetch,params} = serverLoadEvent;
    const {productId} = params;
    if(productId > 5){
            throw error(404,{
                message: 'Product not found',
                hint: 'Try a product id between 1 and 5'
            })
            // throw redirect(307,'/products');
    }
    const title = 'Product details';
    const notification = 'End of season sale! 50% off on all products!';
    const response = await fetch(`http://localhost:4000/products/${productId}`);
    const product = await response.json();
    return {
        title,
        product,
        notification
    };
}

export const prerender = true;
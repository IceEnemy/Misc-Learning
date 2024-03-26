import { DB_USER, DB_PASSWORD } from '$env/static/private'
import {redirect} from '@sveltejs/kit'
import { secretKey } from '$lib/server/secrets';

export const load = ({cookies, url}) => {
    console.log(`Secret Key is ${secretKey}`);
    console.log(`Connecting to database with user ${DB_USER} and password ${DB_PASSWORD}`)
    if(!cookies.get('username')){
        throw redirect(307, `/auth?redirectTo=${url.pathname}`)
    }
    const newsAPIKey = 'NewsAPIKeyHere';
    console.log('News API Key:', newsAPIKey);
    const news = [
        {id : 1, title : 'News 1'},
        {id : 2, title : 'News 2'},
        {id : 3, title : 'News 3'}
    ]
    return {news};
};



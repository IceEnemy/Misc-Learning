import {PUBLIC_BASE_URL} from '$env/static/public';

export const load = () => {
    console.log(`Base URL is ${PUBLIC_BASE_URL}`);
    return{};
}
// cant import the private variables
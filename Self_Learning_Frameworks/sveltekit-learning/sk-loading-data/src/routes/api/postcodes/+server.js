export async function GET(){
    const response = await fetch("http://localhost:4000/postcodes");
    const postcodes = await response.json();
    const appPostCodes = postcodes.map(pcode => {
        return {
            postcode: pcode.postcode,
            suburb: pcode.suburb
        }
    });
    return new Response(JSON.stringify(appPostCodes), {
        headers: {
            'content-type': 'application/json'
        }
    });
}
export const load = async (loadEvent) => {
    const {fetch} = loadEvent;
    const response = await fetch("api/postcodes");
    const postcodes = await response.json();
    const addressList = postcodes.map(pcode => {
        return `${pcode.postcode}, ${pcode.suburb}`;
    });
    return {addressList};
}
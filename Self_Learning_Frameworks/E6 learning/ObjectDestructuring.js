const address = {
    street: '',
    city: '',
    country: ''
};

// Old way
// const street = address.street;
// const city = address.city;
// const country = address.country;

// New way

const { street, city, country } = address;

//defining alias
// const { street: st } = address;
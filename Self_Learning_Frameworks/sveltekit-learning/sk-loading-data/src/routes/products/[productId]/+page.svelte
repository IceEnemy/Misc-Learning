<script>
    export let data;
    const title = data.title;
    const product = data.product;
</script>

<h1>Hello</h1>

<h1>{title}</h1>
<div>
    <h2>{product.name}</h2>
    <p>{product.description}</p>
    <p>{product.price}</p>
    <button>Add to cart</button>
</div>
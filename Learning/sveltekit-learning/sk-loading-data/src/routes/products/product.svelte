<script>
    export let product;
</script>

<a href={`/products/${product.id}`}>
    <h2>{product.name}</h2>
</a>
<p>{product.description}</p>
<hr />
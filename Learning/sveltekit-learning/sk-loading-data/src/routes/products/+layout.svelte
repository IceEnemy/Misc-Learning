<script>
    export let data;
    const title = data.title;
    const featuredProducts = data.featuredProducts;
    const username = data.username;
</script>

<slot />

<h1>{title} for {username}</h1>
{#each featuredProducts as product}
    <div class="product-item">
        <h2>{product.name}</h2>
        <p>{product.description}</p>
        <p>{product.price}</p>
        <button>Add to cart</button>
    </div>
{/each}

<style>
    .product-item{
        display: inline-block;
        width: 200px;
        margin:10px;
        border: 1px solid #ccc;
        padding: 10px;
    }
</style>
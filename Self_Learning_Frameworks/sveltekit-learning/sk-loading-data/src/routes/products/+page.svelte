<script>
    export let data;
    const products = data.products;
    const Component = data.Component;
</script>

<h1>{data.title} for {data.username}</h1>

{#each products as product}
    <div>
        <Component {product} />
    </div>
{/each}


<script>
    import { goto, beforeNavigate, afterNavigate } from '$app/navigation';
    const handleClick = () => {
        console.log('Order placed');
        goto('/products', { replaceState: true }); // replaceState: true will replace the current history state
    }
    beforeNavigate((navigation) => {
            console.log('before navigation:', navigation);
        });
        afterNavigate((navigation) => {
            console.log('after navigation:', navigation);
    });
</script>

<h1>Welcome home!</h1>

<a href="/blog">Blog</a>
<a href="/products">Products</a>

<button on:click={handleClick}>Place Order</button>
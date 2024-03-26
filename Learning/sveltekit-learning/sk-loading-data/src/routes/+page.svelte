<script>
    import {goto, preloadData, preloadCode} from '$app/navigation';
    export let data;
</script>

<h1>Welcome to SvelteKi @ {data.currentTime}</h1>
<p>Visit <a href="https://kit.svelte.dev">kit.svelte.dev</a> to read the documentation</p>

<a href="/products" data-sveltekit-preload-code="hover">Products</a>

<button 
    on:focus={async () => {
        await preloadData('/products');
    }}
    on:mouseover={async () => {
        await preloadData('/products');
    }}
    on:click={() => {
        goto('/products');
}}>Goto Products</button>
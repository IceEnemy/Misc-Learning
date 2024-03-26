<script>
    import {invalidate, invalidateAll} from '$app/navigation';
    
    export let data;

    function refresh(){
        // invalidate('stocks:actively-trading')
        invalidateAll() // invalidates all routes including the layout
    }
</script>

<h1>Actively Trading Stocks</h1>

{#each data.stocks as stock}
    <h2>{stock.symbol} - ${stock.price}</h2>
{/each}

<button on:click={refresh}>Refresh</button>
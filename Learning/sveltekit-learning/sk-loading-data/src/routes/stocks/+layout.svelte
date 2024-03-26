<script>
    export let data;
</script>

<span>Most active stock - {data.mostActiveStock.symbol} {data.mostActiveStock.price}</span>
<span>Top gaining stock - {data.topGainingStock.symbol} {data.topGainingStock.price}</span>
<span>Top losing stock - {data.topLosingStock.symbol} {data.topLosingStock.price}</span>

<slot />

<style>
    span {
        margin-right: 30px;
        font-size: 24px;
    }
</style>
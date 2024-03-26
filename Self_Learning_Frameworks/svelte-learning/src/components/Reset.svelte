<script>
    import { count } from '../stores/stores.js';
    function reset() {
        count.set(0);
    }
</script>

<button on:click={reset}>Reset</button>
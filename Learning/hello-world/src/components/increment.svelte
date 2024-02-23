<script>
    import { count } from '../stores/stores.js';
    function increment() {
        count.update(n => n + 1);
    }
</script>

<button on:click={increment}>Increment</button>
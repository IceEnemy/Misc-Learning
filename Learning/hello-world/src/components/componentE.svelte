<script>
    import { getContext } from "svelte";

    const userName = getContext('username-context');
</script>

<h2>Child E Component</h2>
<h2>Child E userName - {userName}</h2>

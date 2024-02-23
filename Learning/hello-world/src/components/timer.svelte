<script>
    import { time, elapsedTime} from '../stores/stores.js';

    const dateFormater = new Intl.DateTimeFormat('en', {
        hour: 'numeric',
        minute: '2-digit',
        second: '2-digit'
    });
</script>

<h2>The time is {dateFormater.format($time)}</h2>
<h2>You've been viewing this page for {$elapsedTime} seconds</h2>




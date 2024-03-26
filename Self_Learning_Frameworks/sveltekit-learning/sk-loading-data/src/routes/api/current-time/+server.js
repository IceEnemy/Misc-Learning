export async function GET(){
    console.log('curr time GET handler called')
    return new Response(new Date().toLocaleTimeString())
}


import {comments} from '$lib/comments';
import {json} from '@sveltejs/kit';

export function GET(requestEvent){
    const {params} = requestEvent;
    const {commentid} = params;
    const comment = comments.find(c => c.id == commentid);
    return json(comment);
}

export async function PATCH(requestEvent){
    const {params, request} = requestEvent;
    const {commentid} = params;
    const {text} = await request.json();
    const comment = comments.find(c => c.id == commentid);
    comment.text = text;
    return json(comment);
}

export async function DELETE(requestEvent){
    const {params} = requestEvent;
    const {commentid} = params;
    const deletedComment = comments.find(c => c.id == commentid);
    const index = comments.findIndex(c => c.id == commentid);
    comments.splice(index, 1);
    return json(deletedComment);
}
# Create your views here.



from django.shortcuts import render_to_response

from ourstory.models import OurStory

def story(request):
    storys = OurStory.objects.all()
    return render_to_response('story.html',{'storys':storys})



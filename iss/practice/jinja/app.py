import falcon
from jinja2 import Environment, FileSystemLoader

app = falcon.App()
jinja2_env = Environment(loader=FileSystemLoader("templates"))

class MyResource:        
    def on_get(self, req, resp):                
        template = jinja2_env.get_template("index.html")                
        rendered_template = template.render(id=1, name="GFG User")                
        resp.status = falcon.HTTP_200                
        resp.content_type = "text/html"                
        resp.text = rendered_template

app.add_route("/", MyResource())    

if __name__ == "__main__":          
    from wsgiref import simple_server          
    httpd = simple_server.make_server("127.0.0.1", 8000, app)          
    print("Serving on http://127.0.0.1:8000")          
    httpd.serve_forever()

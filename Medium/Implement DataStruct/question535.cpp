class Solution {
public:
    unordered_map<string, string> encoder;
    unordered_map<string, string> decoder;
    int i = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encoder.find(longUrl) != encoder.end()){
            return (encoder[longUrl]);
        } else {
            string url = to_string(i++);
            encoder[longUrl] = url;
            decoder[url] = longUrl;
            return url;
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decoder[shortUrl];
    }
};